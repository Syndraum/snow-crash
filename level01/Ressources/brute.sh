#! /bin/bash -

PATH=/bin:/usr/bin

declare -r dict="rockyou.txt"
declare -r init_hash="42hDRfypTqqnw"

main() {
    local hash="${1:-$init_hash}"
    local salt="${hash:0:2}"
    local gen_hash

    printf "target : %s - salt : %s\n" "$hash" "$salt"
    while read password; do
        gen_hash=$(openssl passwd -salt "$salt" "$password" 2> /dev/null)
        if [[ "$hash" == "$gen_hash" ]]; then
            printf "find - pass: %s\n" "$password"
            break
        fi
    done < "$dict"
}

main "$@"