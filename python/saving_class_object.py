import pickle
import numpy as np


class DataClass:

    def __init__(self):
        self.data_list = [1, 2, 3, 4, 5]
        self.data_set = {"apple", "orange", "banana"}
        self.data_dict = {"a": 1000, "b": 20000, "c": 3000}

    def __add__(self, number):
        new_data_list = []
        for e in self.data_list:
            new_data_list.append(e + number)
        self.data_list = new_data_list


data_obj = DataClass()
with open('obj_data.pkl', 'wb') as f:
    pickle.dump(data_obj, f)


with open('obj_data.pkl', 'rb') as f:
    data_obj1 = pickle.load(f)
