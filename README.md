# Tiny SS
Tiny SS - list what ports are in use, with just a bit of C

## Build
```bash
gcc tinyss.c -o tinyss
```

## Usage
```bash
./tinyss [-j] [max_port]
```

Add `-j` to output in JSON format.

## Example
```bash
demohost$ ./tinyss 10000
21,80,53,1337
```