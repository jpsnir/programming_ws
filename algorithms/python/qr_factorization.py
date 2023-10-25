import numpy as np

m = np.random.normal(2, 2, [5, 5])
print(m)

q, r = np.linalg.qr(m)

print(f'q = {q}')
print(f'q^t.q = {q.T@q}')
print(f'r = {r}')
print(f'r^t.r = {r.T@r}')
