#!/usr/bin/python3
import sys
import signal
import re


def print_stats(file_size, status_codes):
    print("File size: {}".format(file_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))


def signal_handler(sig, frame):
    print_stats(file_size, status_codes)
    sys.exit(0)


file_size = 0
status_codes = {str(code): 0 for code in [
    200, 301, 400, 401, 403, 404, 405, 500]}
line_count = 0

signal.signal(signal.SIGINT, signal_handler)

for line in sys.stdin:
    try:
        parts = re.search(
            r'(\d+\.\d+\.\d+\.\d+) - \[(.+)\] "GET /projects/260 HTTP/1.1" (\d+) (\d+)', line)
        if parts is None:
            continue
        status_code = parts.group(3)
        size = int(parts.group(4))
        file_size += size
        if status_code in status_codes:
            status_codes[status_code] += 1
        line_count += 1
        if line_count % 10 == 0:
            print_stats(file_size, status_codes)
    except Exception as e:
        continue

print_stats(file_size, status_codes)
