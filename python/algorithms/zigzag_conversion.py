class Solution:
    def convert(self, s: str, numRows: int) -> str:
        zigzag_string = ""

        # store strings in row
        # Treat everything as a 2D linked list and
        # then later parse the string
        # The gap between letters in the same row stays constant.
        # Find a formula to compute the gap of the letters, then assign rows.
        row_strings = []
        for row in range(0, numRows):
            row_char_list = []
            for (char_id, c) in enumerate(s):
                row_flag, space_flag = self.row_placement_condition(
                    char_id, row, numRows, len(s))
                if row_flag:
                    row_char_list.append(c)
                if space_flag:
                    row_char_list.append(" ")

            # convert list to string and append row
            row_strings.append(''.join(row_char_list))

        for s in row_strings:
            zigzag_string = zigzag_string + s + '\n'

        return zigzag_string

    def row_placement_condition(self, char_id: int, row_id: int, num_rows: int, slen: int):
        num_mid_rows = num_rows - 2
        first_row_ids = []
        for i in range(0, slen):
            if i == 0:
                first_row_id = (2*num_mid_rows+2)*i
            else:
                first_row_id = (2*num_mid_rows+1)*i+1
        if row_id == 0 and char_id == 2*num_mid_rows - 1
