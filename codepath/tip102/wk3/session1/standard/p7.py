def post_compare(draft1, draft2):
    def build(text):
        stack = []
        for ch in text:
            if ch == "#":
                if stack:
                    stack.pop()
            else:
                stack.append(ch)
        return "".join(stack)
    return build(draft1) == build(draft2)