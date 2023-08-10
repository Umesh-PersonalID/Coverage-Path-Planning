import requests
from bs4 import BeautifulSoup
import csv

url = 'https://idss.mit.edu/people/directory/page/4/'
response = requests.get(url)

soup = BeautifulSoup(response.content, 'html.parser')

professors = []

for item in soup.select('.person-card'):
    name = item.select_one('.person-card__name').text.strip()
    email = item.select_one('.person-card__email').text.strip()
    professors.append([name, email])

with open('professors.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Name', 'Email'])
    writer.writerows(professors)
