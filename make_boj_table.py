import os
from bs4 import BeautifulSoup
import requests as req
import pandas as pd
import csv

solved_problems_DB = pd.read_csv('solved_problems.csv')

SECONDS_IN_A_DAY = 60*60*24
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.99 Safari/537.36"
}
data_set = {}
file_name_extension = {}


class AutoBoj:
    def __init__(self, configure_obj):
        self.git_name = configure_obj["git_name"]
        self.git_email = configure_obj["git_email"]
        self.git_repo = configure_obj["git_repo"]
        self.boj_name = configure_obj["boj_name"]

    def set_up_git(self):
        script = [f'git config --global user.name "{self.git_name}"',
                  f'git config --global user.email "{self.git_email}"',
                  f'git add .',
                  'cls']
        for i in script:
            os.system(i)

    def check_file(self):
        path_dir = os.path.dirname(os.path.realpath(__file__))
        file_list = os.listdir(path_dir + "/boj/")
        for i in file_list:
            try:
                solved_problems_DB.loc[0, os.path.splitext(i)[0][4:]]
                file_name_extension[os.path.splitext(i)[0]] = "cpp" if os.path.splitext(i)[1] == ".cpp" else "py" if os.path.splitext(i)[
                    1] == ".py" else "java" if os.path.splitext(i)[1] == ".java" else "None"
            except KeyError:
                continue

    def crawl_user_data(self):
        print("Please wait. Started Crawling...")
        url = f"https://www.acmicpc.net/user/{self.boj_name}"
        html = req.get(url, headers=headers)
        soup = BeautifulSoup(html.content, 'html.parser')
        li = soup.find("div", {"class": "panel-body"}).findAll("span")

        def load_data_status(problem_id):
            url = f"https://www.acmicpc.net/status?problem_id={problem_id}&user_id={self.boj_name}"
            html = req.get(url, headers=headers)
            soup = BeautifulSoup(html.content, 'html.parser')
            table = soup.find(
                "table", {"class": "table table-striped table-bordered"}).findAll("tbody")
            for i in table:
                scoring_num = i.find("td").text
                data_original_title = i.find(
                    "a", {"class": "real-time-update"}).attrs["title"]
                return [scoring_num, data_original_title]

        for i in range(len(li)):
            if i % 2 == 0:
                problem_number = li[i].text
                problem_title = li[i+1].text

                try:
                    data_set[problem_number] = [problem_title, solved_problems_DB.loc[1, problem_number]]
                except KeyError:
                    status = load_data_status(problem_number)
                    if li[i]:
                        data_set[problem_number] = [problem_title, status[1]]
        df = pd.DataFrame.from_dict(data_set)
        df.to_csv("solved_problems.csv")

    def write_markdown(self):
        li = []
        with open("BOJ.md", "w", encoding="UTF8") as file:
            title = f"""|No|Title|Solution Link|Problem Link|Last Solve|\n| :--: | :--: | :--: | :--: | :--: |\n"""
            file.write(title)
            for number in data_set:
                try:
                    extension = "cpp" if file_name_extension["boj_"+number] == "cpp" else "py" if file_name_extension["boj_" +
                                                                                                                      number] == "py" else "java" if file_name_extension["boj_"+number] == "java" else "None"
                except KeyError:
                    print(
                        f"error: No.{number} File not found.\nPlease download the code from http://boj.kr/{number}.")
                    continue
                li.append(
                    f"""|{number}|**{data_set[number][0]}**|[/boj/boj_{number}.{extension}]({self.git_repo}/blob/master/boj/boj_{number}.{extension})|[http://boj.kr/{number}](https://www.acmicpc.net/problem/{number})|{data_set[number][1]}|\n""")
            for i in li:
                file.write(i)

    def commit(self):
        print("If you want commit?(Y/N)")
        cmd = input("> ")
        if cmd == "Y" or cmd == "y" or cmd == "Yes" or cmd == "yes":
            script = ['git pull', 'git add --all',
                      f'git commit -m "{commit_message}"', 'git push origin', 'cls']
            for i in script:
                os.system(i)
            print("Complete. Relaunching...")
        elif cmd == "N" or cmd == "n" or cmd == "No" or cmd == "no":
            print("Ok.")
        os.system(f"TIMEOUT {SECONDS_IN_A_DAY}")
        AutoBoj.check_file(self)
        AutoBoj.crawl_user_data(self)
        AutoBoj.write_markdown(self)
        AutoBoj.commit(self)


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
    ab.set_up_git()
    ab.check_file()
    ab.crawl_user_data()
    ab.write_markdown()
    ab.commit()
