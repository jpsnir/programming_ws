# NOTES:

# The problem is in computation complexity. Need to impose more constraints to make it faster.
# Some ideas - start from the biggest substring so that biggest string is predicted first.
# Try the hint and figure out how to implement it.
# Improve on string and list indexing
#


class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        end = 0
        longest = 0
        longest_palindromic_string = ""

        for start in range(0, len(s)):
            for end in range(start, len(s)):
                sub_string = s[start:end+1]
                # print(f"start index : {start}, end index - {end}, substring - {sub_string} is palindrome: {self.isPalindrome1(sub_string)}")
                if (self.isPalindrome1(sub_string)):
                    if (len(sub_string) > longest):
                        longest = len(sub_string)
                        longest_palindromic_string = sub_string

        return longest_palindromic_string

    def isPalindrome(self, sub_s: str):
        isPalindrome = False
        reverse_string = sub_s[::-1]
        if reverse_string == sub_s:
            isPalindrome = True
        return isPalindrome

    def isPalindrome1(self, sub_s: str):
        isPalindrome = False
        if len(sub_s) == 1:
            return True
        if len(sub_s) % 2 == 0:
            m = len(sub_s)//2
            # slicing strings to m
            s1 = sub_s[0:m]
            # slicing string from m+1 to end
            s2 = sub_s[m:]
            s2_reverse = s2[::-1]
            if s1 == s2_reverse:
                isPalindrome = True
        else:
            # odd number
            # middle character is not taken into account
            m = len(sub_s)//2
            # slicing string to m
            s1 = sub_s[0:m]
            # slicing string from m+2
            s2 = sub_s[m+1:]
            s2_reverse = s2[::-1]
            if s1 == s2_reverse:
                isPalindrome = True

        return isPalindrome


s = 'babad'
soln = Solution()
lps = soln.longestPalindrome(s)
print(f'longest palindrome string: {lps}')
