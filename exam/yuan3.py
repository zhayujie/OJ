import sys

if __name__ == '__main__':
    ins = sys.stdin.readline().strip().split()
    n = int(ins[0])
    m = int(ins[1])
    classes = []
    people = {}
    for i in range(m):
        st = sys.stdin.readline().strip().split()
        students = []
        for j in range(int(st[0])):
            students.append(st[3+j])
            people[students[st[3+j]]]
        d = {'teacher': st[1], 'tid': st[2], 'name': st[3], 'students': students, 'score': 0}
        classes.append(d)

    logs = []
    for k in range(n):
        dl = []
        st = sys.stdin.readline().strip().split()
        dl.append(st[0])
        dl.append(st[1])
        dl.append(st[2])
        logs.append(dl)

    inlogs = {}
    for log in logs:
        if log[0] == 'IN':
            inlogs[log[1]] = log[2]
        else:
            count = log[2] - inlogs[log[1]]






