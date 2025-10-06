def validate_html_tags(html):
    s = []
    for t in html:
        if t[1] == '/':
            if not s or s[-1][1:] != t[2:]:
                return False
            s.pop()
        else:
            s.append(t)
    return

html = "<div><p></p></div>"
print(validate_html_tags(html))

html_2 = "<div><p></div></p>"
print(validate_html_tags(html_2))

html_3 = "<div><p><a></a></p></div>"
print(validate_html_tags(html_3))

html_4 = "<div><p></a></p></div>"
print(validate_html_tags(html_4))