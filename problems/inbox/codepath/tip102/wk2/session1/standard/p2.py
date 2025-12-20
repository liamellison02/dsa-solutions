# Standard Problem Set V1, Problem 2
def total_sales(ticket_sales):
    ret = 0
    for k,v in ticket_sales.items():
        ret += v
    return ret