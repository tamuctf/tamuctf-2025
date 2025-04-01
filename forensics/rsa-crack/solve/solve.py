from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.backends import default_backend
import sys

def try_decrypt_key(private_key_path, wordlist_path):
    with open(private_key_path, "rb") as key_file:
        encrypted_key = key_file.read()
    
    with open(wordlist_path, "r", encoding="utf-8", errors="ignore") as wordlist:
        for password in wordlist:
            print(password)
            password = password.strip()
            try:
                private_key = serialization.load_pem_private_key(
                    encrypted_key,
                    password=password.encode(),
                    backend=default_backend()
                )
                print(f"Password found: {password}")
                return password
            except Exception:
                pass
    
    print("No valid password")
    return None

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 script.py <encrypted_key_path> <wordlist_path>")
        sys.exit(1)
    
    private_key_path = sys.argv[1]
    wordlist_path = sys.argv[2]
    
    found_password = try_decrypt_key(private_key_path, wordlist_path)
    if found_password:
        sys.exit(0)
    else:
        sys.exit(1)
