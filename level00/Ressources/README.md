### Documentation
[Permission matters](https://tbhaxor.com/exploiting-file-permissions-misconfigurations/)

### External
```
BASH  rot
```

### Exploit
1. `find / -user flag00 2> /dev/null`
   ```bash
   /usr/sbin/john
   /rofs/usr/sbin/john
   ```

2. `ls -la /usr/sbin/john`
   ```bash
   ----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
   ```

3. `cat /usr/sbin/john`
   ```bash
   cdiiddwpgswtgt
   ```

4. `./rot cdiiddwpgswtgt 11`
   ```bash
   nottoohardhere
   ```

5. `su flag00` pass : nottoohardhere
   ```bash
   getflag
   ```
