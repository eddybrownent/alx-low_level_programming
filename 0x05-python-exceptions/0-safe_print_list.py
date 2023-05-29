#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    count = 0
    for item in my_list:
        try: 
            print(item, end='')
            count += 1
        except TypeError:
            pass
    print()
    return count
