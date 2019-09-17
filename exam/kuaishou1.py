import sys
# 2001:db8:85a3:0:0:8A2E:0370:7344

if __name__ == '__main__':
    flag = 1
    st = sys.stdin.readline().strip()
    l1 = st.split('.')
    l2 = st.split(':')
    # print(l1)
    if len(l1) == 4:
        for i in l1:
            if int(i) < 0 or int(i) > 255:
                print('Neither')
                flag = 0
                break
            elif len(i) > 1 and i[0] == '0':
                print('Neither')
                flag = 0
                break
            else:
                continue
        if flag == 1:
            print('IPv4')

    elif len(l2) == 8:
        for i in l2:
            # print('i2: ' + i)
            if len(i) == 0 or len(i) > 4:
                print('Neither')
                flag = 0
                break
            elif len(i) > 0:
                if i == '00' or i == '000' or i == '0000':
                    print('Neither')
                    flag = 0
                    break
        if flag == 1:
            print('IPv6')

    else:
        print('Neither')
