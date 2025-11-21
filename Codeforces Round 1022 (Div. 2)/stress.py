# stress.py
import subprocess, random, sys

def gen_input():
    # example: n between 1 and 100, values 0..1000
    n = random.randint(1, 100)
    nums = [str(random.randint(0,1000)) for _ in range(n)]
    return f"{n}\n{' '.join(nums)}\n"

def run(prog, inp):
    p = subprocess.run([prog], input=inp, text=True,
                       capture_output=True)
    return p.stdout, p.stderr

def main():
    i = 0
    while True:
        i += 1
        inp, err  = run("gen.exe","")
        out1, err1 = run("sol2.exe", inp)
        out2, err2 = run("sol1.exe", inp)

        if out1 != out2 or err1 != err2:
            print(f"❌ Divergence on test #{i}\n")
            print("---- INPUT ----")
            print(inp, end="")
            print("---- sol1 STDOUT ----")
            print(out1)
            print("---- sol2 STDOUT ----")
            print(out2)
            if err1 or err2:
                print("---- sol1 STDERR ----", err1)
                print("---- sol2 STDERR ----", err2)
            sys.exit(1)

        # if i % 100 == 0:
        print(f"✔ {i} tests OK")

if __name__ == "__main__":
    main()
