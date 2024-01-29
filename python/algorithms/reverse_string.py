'''
Reverse each word of a string using stack.
author: jagatpreet

adapted from : geeks for geeks
'''

import typing


def reverse_words(sentence: str):
    st = list()
    for i in range(len(sentence)):
        if sentence[i] != " ":
            st.append(sentence[i])

        else:
            while len(st) > 0:
                print(st[-1], end="")
                st.pop()
            print(end=" ")

    # For the last word
    while len(st) > 0:
        print(st[-1], end="")
        st.pop()
    print()


if __name__ == "__main__":
    sentence = "Geeks for geeks"
    reverse_words(sentence)
