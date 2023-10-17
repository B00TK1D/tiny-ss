# Tiny SS
Tiny SS - list what ports are in use, with just a bit of C

## Build
```bash
gcc tinyss.c -o tinyss
```

## Usage
```bash
./tinyss [max_port]
```

## Example
```bash
demohost$ ./tinyss 10000
21,80,53,1337
```