# Advanced Problem Set V1, Problem 2
def can_trust_message(message):
    freq = {} 
    for c in message:
        if c == " ":
            continue
        freq.add(c)
    return (len(freq)==26)
