def getTotalPage(post_total, post_page):
    ret = post_total // post_page
    if post_total % post_page == 0:
        return ret
    return ret + 1

print(getTotalPage(20, 10))