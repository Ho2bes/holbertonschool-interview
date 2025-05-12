#!/usr/bin/python3
import re
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    if word_count is None:
        word_count = {}
        for word in word_list:
            w = word.lower()
            word_count[w] = word_count.get(w, 0) + 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Python/requests:RedditKeywordCounter:v1.0'}
    params = {'limit': 100, 'after': after}

    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False
    )
    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])

    for post in posts:
        title = post['data']['title'].lower()
        words = re.findall(r'\b\w+\b', title)
        for word in words:
            if word in word_count:
                word_count[word] += 1

    after = data.get('after')
    if after is not None:
        return count_words(subreddit, word_list, after=after,
                           word_count=word_count)

    sorted_counts = sorted(
        [(k, v) for k, v in word_count.items() if v > 0],
        key=lambda x: (-x[1], x[0])
    )
    for word, count in sorted_counts:
        print(f"{word}: {count}")
