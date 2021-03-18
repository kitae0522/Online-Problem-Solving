import os
from bs4 import BeautifulSoup
import requests as req
import pandas as pd

solved_problems_DB = pd.read_csv('solved_problems.csv')

headers = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.86 Safari/537.36"
}
data_set = {}
file_name_extension = {}


class AutoBoj:

    __VERSION__ = '1.0.4'

    def __init__(self, configure_obj:dict) -> None:
        self.git_name = configure_obj["git_name"]
        self.git_email = configure_obj["git_email"]
        self.git_repo = configure_obj["git_repo"]
        self.boj_name = configure_obj["boj_name"]

    def set_up_git(self) -> None:
        script = [f'git config --global user.name "{self.git_name}"',
                  f'git config --global user.email "{self.git_email}"',
                  f'git add .']
        for i in script:
            os.system(i)

    def check_file(self) -> None:
        file_list = os.listdir(os.path.join("boj/"))
        for i in file_list:
            try:
                solved_problems_DB.loc[0, os.path.splitext(i)[0][4:]]
            except KeyError:
                continue
            file_name_extension[os.path.splitext(i)[0]] = os.path.splitext(i)[1][1:]

    def crawl_solved_p(self) -> None:
        print("Please wait. Started Crawling...")
        solved_li = BeautifulSoup(req.get(f"https://www.acmicpc.net/user/{self.boj_name}", headers=headers).content, 'html.parser').find("div", {"class": "panel-body"}).find_all("a")

        def solved_p_info(problem_id : int) -> str:
            get_data = req.get(f"https://api.solved.ac/v2/search/recommendations.json?query={problem_id}").json()["result"]["problems"][0]
            problem_title = get_data["title"]
            return problem_title

        for i in range(len(solved_li)):
            problem_number = solved_li[i].text
            try:
                data_set[problem_number] = solved_problems_DB.loc[0, problem_number], solved_problems_DB.loc[1, problem_number]
            except KeyError:
                problem_title = solved_p_info(problem_number)
                print(
                    f"Epoch : {i+1}/{len(solved_li)} | Problem : \"{problem_title}\" (No.{problem_number}) ")
                data_set[problem_number] = [problem_title, f"https://www.acmicpc.net/problem/{problem_number}"]
        df = pd.DataFrame.from_dict(data_set)
        df.to_csv("solved_problems.csv")

    def write_markdown(self) -> None:
        li = []
        with open("BOJ.md", "w", encoding="UTF8") as file:
            title = f"""|No|Title|Solution Link|Problem Link|\n| :--: | :--: | :--: | :--: |\n"""
            file.write(title)
            index = 1
            for number in data_set:
                try:
                    extension = file_name_extension[f"boj_{number}"]
                except KeyError:
                    print(
                        f"error: No.{number} File not found.\nPlease download the code from http://boj.kr/{number}.")
                    continue
                li.append(
                    f"""|{number}|**{data_set[number][0]}**|[/boj/boj_{number}.{extension}]({self.git_repo}/blob/master/boj/boj_{number}.{extension})|[http://boj.kr/{number}]({data_set[number][1]})|\n""")
            for i in li:
                file.write(i)

    def commit(self) -> None:
        print("If you want commit?(Y/N)")
        cmd = input("> ")
        if cmd == "Y" or cmd == "y" or cmd == "Yes" or cmd == "yes":
            script = ['git pull', 'git add --all',
                      f'git commit -m "{commit_message}"', 'git push origin', 'clear']
            for i in script:
                os.system(i)
            print("Complete. Relaunching...")
        elif cmd == "N" or cmd == "n" or cmd == "No" or cmd == "no":
            print("Ok.")


if __name__ == "__main__":
    """
    if there is a commit message you want,
    please correct it here.
    """
    commit_message = "update"

    """
    And these are the things you need to set up.
    example:
        # git_name = "kitae0522"
        # git_email = "kitae0522@naver.com"
        # git_repo = "https://github.com/kitae0522/test"
        # boj_name = "kitae0522"
    """
    ab = AutoBoj({"git_name": "kitae0522",
                  "git_email": "kitae0522@naver.com",
                  "git_repo": "https://github.com/kitae0522/Online-Problem-Solving",
                  "boj_name": "kitae0522"})
    os.system("clear")
    print(f"Boj Table Maker\nVersion : {ab.__VERSION__}\nAuthor : Song Kitae")
    ab.set_up_git()
    ab.check_file()
    ab.crawl_solved_p()
    ab.write_markdown()
    ab.commit()
