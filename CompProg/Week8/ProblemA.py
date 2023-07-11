import sys
    
def makePalindrome(z):
    x = ""
    odd = len(z) % 2 != 0
    for i in x[::-1]:
        x += z[i]
    print("Returning string of length " + str(len(x)))
    return x

def main():
    a = str(sys.stdin)
    b = str(sys.stdin)
    ax = makePalindrome(a)
    bx = makePalindrome(b)
    print(ax)
    print(bx)
    return 0

main()
    