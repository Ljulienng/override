hex_str = "0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d"
hex_values = hex_str.split("0x")

for s in hex_values:
    bytes_data = bytes.fromhex(s)
    reversed_bytes = bytes_data[::-1]
    print(reversed_bytes.decode(), end='')