1. `gdb ./level08` 

2. `disassemble main`
   ```bash
    # main
    # if argc == 1
    #   exit
    # if "token" in argv[1]
    #   exit
    # try
    #   open argv[1]
    #   read rgv[1]
    #   write stdout
    # catch
    #   exit
    ```

3. `./level08 token`
   ```
   You may not access 'token'
   ```

4. `chmod u+w .`

5. `mv token notToken`

6. `./level08 notToken`
   ```
   quif5eloekouj29ke0vouxean
   ```

7. `su flag08` pass : quif5eloekouj29ke0vouxean
   ```bash
   getflag
   ```
