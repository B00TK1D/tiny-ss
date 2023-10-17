# Tiny SS
Tiny SS - list what ports are in use, with just a bit of C

## Build
```
gcc tinyss.c -o tinyss
```

## Usage
```
./tinyss [max_port]
```

## Example
```
demohost$ ./tinyss 10000
21,80,53,1337
```