import sys

string = sys.stdin.readline().strip()
count = 0

for i in range(len(string)):
    if string[i] == 'P':
        count += 1
        continue

    if i < len(string) - 1 and count >= 2 and string[i + 1] == 'P':
        count -= 2
    else:
        print('NP')
        exit()

if count == 1:
    print('PPAP')
else:
    print('NP')