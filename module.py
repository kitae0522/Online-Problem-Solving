import os
import requests as req
import json


class Make_BOJ_Table:

    def __init__(self, configure_obj: dict):
        self.git_name = configure_obj["git_name"]
        self.git_repo = configure_obj["git_repo"]
        self.boj_name = configure_obj["boj_name"]
        self.user_db = {}

    def crawl_data(self):
        def req_url_handler(u_id: str, page_idx: int = 1) -> str:
            return f'https://solved.ac/api/v3/search/problem?query=solved_by:{u_id}&page={page_idx}'

        def return_problem_img(p_level: int) -> str:
            return f'<img height="25px" width="25px" src="https://static.solved.ac/tier_small/{p_level}.svg"/>'

        solved_req: dict = json.loads(
            req.get(req_url_handler(self.boj_name)).text)
        self.user_db: dict = {
            content['problemId']: [
                content['level'],
                content['titleKo'],
                return_problem_img(content['level'])
            ] for content in solved_req['items']
        }

        idx = 2
        while True:
            if solved_req['count'] == len(self.user_db.keys()):
                break
            else:
                next_req: dict = json.loads(
                    req.get(req_url_handler(self.boj_name, idx)).text)
                next_req_dict: dict = {
                    content['problemId']: [
                        content['level'],
                        content['titleKo'],
                        return_problem_img(content['level'])
                    ] for content in next_req['items']
                }
                self.user_db.update(next_req_dict)
            idx += 1

    def check_file(self):
        for item in os.listdir(f'{os.getcwd()}/boj'):
            x = item.split('.')
            try:
                self.user_db[int(x[0])].append(item)
            except ValueError:
                print(f'❎ 문제 파일 이외에 다른 파일이 있습니다. : {item}')
            except KeyError:
                print(f'❎ 파일은 있지만, 해결하지 않은 문제가 있습니다. : {item}')

    def render_markdown_header(self) -> str:
        return (
            f'<img src="http://mazassumnida.wtf/api/v2/generate_badge?boj={self.boj_name}">'
            f'<img src="http://mazandi.herokuapp.com/api?handle={self.boj_name}&theme=warm">\n'
            f'<h1 style="font-weight:600">{self.boj_name}님이 푼 문제</h1>\n\n'
        )

    def render_table_header(self) -> str:
        return (
            '|Tier|No|Title|Solution Link|Problem Link|\n'
            '| :--: | :--: | :--: | :--: | :--: |\n'
        )

    def render_table_item(self, option) -> str:
        sort_option, direction_option = option
        return_string = ''
        write_by = dict(
            sorted(self.user_db.items(), reverse=direction_option, key=lambda x: x[1][0])) if sort_option == 'tier' else \
            dict(sorted(self.user_db.items(), reverse=direction_option))

        for content in write_by:
            try:
                return_string += \
                    (
                        f'| {self.user_db[content][2]} '
                        f'| {content} '
                        f'| **{self.user_db[content][1]}** '
                        f'| [/boj/{self.user_db[content][3]}](https://github.com/{self.git_name}/{self.git_repo}/blob/master/boj/{self.user_db[content][3]}) '
                        f'| http://boj.kr/{content} |\n'
                    )
            except IndexError:
                print(f'❎ 해결했지만, 파일이 없는 문제가 있습니다. : {content}')
        return return_string

    def run(self, option):
        self.crawl_data()
        self.check_file()
        with open(f'{os.getcwd()}/BOJ.md', 'w', encoding='UTF8') as file:
            file.write(self.render_markdown_header())
            file.write(self.render_table_header())
            file.write(self.render_table_item(option))
        print(f'✅ 업데이트 완료.')
