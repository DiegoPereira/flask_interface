from flask import Flask
app = Flask(__name__)

@app.route("/get_noise")
def get_noise():
    return "Hello World!"

@app.route("/insert_noise")
def insert_noise():
    return "Hello World!"

@app.route("/get_temperature")
def get_temperature():
    return "Hello World!"

@app.route("/insert_temperature")
def insert_temperature():
    return "Hello World!"

@app.route("/get_luminosity")
def get_luminosity():
    return "Hello World!"

@app.route("/insert_luminosity")
def insert_luminosity():
    return "Hello World!"

if __name__ == "__main__":
    app.run()