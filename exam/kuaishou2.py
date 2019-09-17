import sys

res = []
st_map = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']


def create_st(st, cur):
    if len(st) == 0:
        res.append(cur)
        return
    # print(st[0])
    s = st_map[int(st[0])]
    for i in s:
        create_st(st[1:], cur+i)


def tel_sort():
    st = sys.stdin.readline().strip()
    create_st(st, '')
    res_st = '[' + res[0]
    for i in range(1, len(res)):
        res_st += ', ' + res[i]
    res_st += ']'
    print(res_st)


if __name__ == '__main__':
    tel_sort()