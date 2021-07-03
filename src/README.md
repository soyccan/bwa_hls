# Burrows-Wheller Aligner

FM-index of the reference genome should be generated before
the alignment process

## Build
```
make
```

## FM-index generator
```
./index 1.fasta
```
Then `1.fasta.fmi` will be generated

## Aligner
```
./align 1.fasta.fmi 1.fastq
```
