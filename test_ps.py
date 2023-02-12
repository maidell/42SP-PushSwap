import itertools
import subprocess

def str_perm(n):
    perm = list(range(1, n+1))
    perm = itertools.permutations(perm)
    perm = list(perm)
    perm = list(map(lambda tup: list(map(lambda x: str(x), tup)), perm))
    return perm

for tam in [1, 2, 3, 4, 5]:
    print("Testando " + str(tam) + " elementos")
    all_ok = True
    for perm in str_perm(tam):
        push_swap_out = subprocess.run(["./push_swap", *perm], capture_output=True, text=True).stdout
        checker_out = subprocess.run(["./checker_linux", *perm], input=push_swap_out, capture_output=True, text=True).stdout.strip()
        if checker_out != "OK":
            all_ok = False
            print(checker_out + ": " + ' '.join(perm))
    if all_ok:
        print("Tudo OK")
