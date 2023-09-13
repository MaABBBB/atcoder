# coding: utf-8
# Your code here!

H, W = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
flag = None
seen = [[False] * 1000 for h in range(1000)]
field = [input() for h in range(H)]

def dfs (h, w):
    global flag, seen
    seen[h][w] = True
    while (seen[h][w] != True):
        seen[h][w] = True
        nh = None
        nw = None
        for dir in range(4):
            nh = h + dy[dir]
            nw = w + dx[dir]
            if (nh < 0 or nw < 0 or nh >= H or nw >= W): continue
            if (field[nh][nw] == '#'): continue
            if (seen[nh][nw]): continue
            if (field[nh][nw] == '.' and (nh == 0 or nw == 0 or nh == H-1 or nw == W-1)):
                flag = True
                break
        h = nh
        w = nw        
sh = None
sw = None
for h in range(H):
    for w in range(W):
        if (field[h][w] == 'S'):
            sh = h
            sw = w

if (field[sh][sw] == 'S' and (sh == 0 or sw == 0 or sh == H-1 or sw == W-1)): flag = True
else: dfs(sh, sw)

if (flag): print("YES")
else: print("NO")