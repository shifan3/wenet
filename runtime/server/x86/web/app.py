#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright 2021 Mobvoi Inc. All Rights Reserved.
# Author: zhendong.peng@mobvoi.com (Zhendong Peng)

import argparse

from flask import Flask, render_template

parser = argparse.ArgumentParser(description='training your network')
parser.add_argument('--port', default=19999, type=int, help='port id')
parser.add_argument('--ssl', default=False, action="store_true")
args = parser.parse_args()

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    if args.ssl:
        ssl_context = ('cert.pem', 'key.pem')
    else:
        ssl_context = None
    app.run(host='0.0.0.0', port=args.port, debug=False, ssl_context=ssl_context, use_reloader=False)
