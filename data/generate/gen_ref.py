from random import randint as R
import sys

size = sys.argv[1]

fa = open(size + '.fasta', 'w')
fq = open(size + '.fastq', 'w')

ref = []
s = 'ACTG'

for _ in range(int(size)):
    base = s[R(0,3)]
    ref.append(base)

fa.write('>\n')
fa.write(''.join(ref) + '\n')

num_read = 10
for _ in range(num_read):
    read_len = min(128, int(size)//10)
    a = R(0, int(size) - 1)

    read = ref[a:a+read_len]
    mutation = 2
    for _ in range(mutation):
        read[R(0, len(read)-1)] = s[R(0, 3)]

    fq.write('>>>\n')
    fq.write(''.join(read)+'\n')
    fq.write('---\n')
    fq.write('<<<\n')
