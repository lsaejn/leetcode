import requests
import configparser
import os
import json
import time
import datetime
import re
import sys
import html
from selenium.webdriver.common.keys import Keys
from selenium import webdriver


a="fuck-off"
b=(a).replace('-',' ')
options = webdriver.ChromeOptions()
#options.add_argument('headless')
options.add_argument('--disable-gpu')
executable_path = 'C:/Program Files (x86)/Google/Chrome/Application/chromedriver'
driver = webdriver.Chrome(chrome_options=options, executable_path=executable_path)
#driver = webdriver.Chrome()
driver.get('https://leetcode-cn.com/problemset/all/')
time.sleep(2)
op_selector = driver.find_elements_by_class_name('form-control')
op_selector=op_selector[1]
options_list = op_selector.find_elements_by_tag_name('option')
for option in options_list:  # 获取country dropdownlist里所有的数据
    if option.get_attribute("value") =="9007199254740991":
        option.click()
pro_attr = driver.find_elements_by_class_name('reactable-data')
pro_attr = pro_attr[0]
problems_list=pro_attr.find_elements_by_tag_name('tr')
print(len(problems_list))

questions={}#题号到中文的映射
# for problem in problems_list:
#     trs=problem.find_elements_by_tag_name('td')
#     a=problem.find_element_by_tag_name('a')
#     #print(a.get_attribute("href"))
#     print(a.text)
#     print(trs[1].text)
#     s=a.get_attribute('href')
#     print(type(s))
#     i=len(s)-1
#     while s[i]!='/':
#         i-=1
#     eName=s[i+1:]
#     questions[eName] =a.text
driver.get('https://leetcode-cn.com/accounts/login/')
driver.find_element_by_name('login').send_keys('15101073917')
driver.find_element_by_name('password').send_keys('6282881sxx')
# driver.find_element_by_id('id_remember').click()
btn = driver.find_element_by_tag_name('button')
print(btn)
btn.click()
time.sleep(3)

limit = 20
offset = 0
submissions=[]
while True:
    submissions_url = '{}/api/submissions/?format=json&limit={}&offset={}'.format(
        'https://www.leetcode-cn.com', limit, offset
    )
    resp = driver.get(submissions_url)
    data = resp.json()
    if 'has_next' not in data.keys():
        raise Exception('Get submissions wrong, Check network\n')

    submissions += data['submissions_dump'] if data['status_display'] == 'Accepted' else print("failed subm")
    if data['has_next']:
        offset += limit
    else:
        break
