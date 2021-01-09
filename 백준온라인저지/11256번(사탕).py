# 문제 해결 방식 #

# 그리디 알고리즘 지식이 필요한 문제이다.
# 상자의 세로길이 R와 가로길이 C를 곱인 R * C가 상자의 넓이면서 동시에
# 상자에 담을 수 있는 사탕의 개수이다.

# 즉, 사탕 갯수 J와 상자의 개수 N을 입력하여 각각 변수(temp1, temp2)에 저장을 한 후,
# 두 변수의 곱을 box 리스트에 저장한다.
# 다 저장 한다음 오름차순으로 정렬하여 box 리스트의 가장 큰 값(가장 큰 상자)인 맨 오른쪽 원소 값부터
# 차례로 pop하여 사탕의 개수인 변수 J값과 빼고 그 결과를 사탕의 개수인 J변수에 저장한다.
# 변수 J 값이 0 이하가 될 때까지 계속 빼주고 상자의 개수인 box_cnt 변수를 1씩 증가시켜주면
# 최소한의 필요한 상자 수를 구할 수 있게 된다.

T = int(input())        # 테스트 케이스 수 입력

for i in range(T):
    box = []            # 상자의 크기를 저장할 리스트 생성
    J, N = map(int, input().split())     # 상자의 가로, 세로 길이 입력
    box_cnt = 0         # 상자 갯수를 저장할 변수
    for j in range(N):  # 상자의 갯수만큼 반복
        temp1, temp2 = (map(int, input().split())) # 상자의 가로, 세로 길이 정보 입력
        box.append(temp1*temp2)     # 가로, 세로 길이를 곱하여 각 상자의 넓이를 box 리스트에 저장.
    box.sort()                      # box에 저장하여 상자의 크기가 작은 순부터 큰순으로 오름차순 정렬
    while True:
        if J > 0:                   # 상자의 크기가 곧 포장할 수 있는 사탕의 개수이므로,
            J -= box.pop()          # 사탕의 개수인 J에서 상자의 크기순으로 정렬된 box 리스트에서 가장 큰 상자로 사탕을 포장하기 위해 사탕의 개수 J에서 사탕 포장 가능 갯수인 상자 크기를 뺀다.
            box_cnt += 1            # 포장을 했으니, 포장한 상자 개수 1증가.
        else:                       # 사탕을 전부 포장했다면
            print(box_cnt)          # 포장한 상자 개수 출력하고 while문 탈출.
            break