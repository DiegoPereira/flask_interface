import datetime
from pymongo import MongoClient

class DataHandler(object):
    def __init__(self, db_url):

        self.client = MongoClient(db_url)
        self.db = self.client.sensor
        self.noise_collection = self.db.noise
        self.temperature_collection = self.db.temperature
        self.luminosity_collection = self.db.luminosity

    def insert_noise_data(self, value):
        pass

    def get_noise_data(self):
        pass

    def insert_temperature_data(self, value):
        pass

    def get_temperature_data(self):
        pass

    def insert_luminosity_data(self, value):
        pass

    def get_luminosity_data(self):
        pass


