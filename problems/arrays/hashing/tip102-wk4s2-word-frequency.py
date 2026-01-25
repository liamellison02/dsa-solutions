def word_frequency_analysis(t):
    freq = {}
    t = t.lower()
    s = t.split()
    for w in s:
        freq = freq.get(w, 0) + 1
    return freq