#pragma once

#include <vector>
#include "Person.hpp"

class Person;

/**
 * A class representing a Vehicle. Serves as a base class for specific types of vehicles (sedans, motorcycles, etc.).
 */
class Vehicle {
public:
    /**
     * Constructor for Vehicle
     * @param name name of Vehicle
     * @param price price of Vehicle in dollars
     * @param wheels wheels on Vehicle
     * @param doors doors on Vehicle
     * @param seats seats in Vehicle
     * @param maxPassengers max passengers fittable in Vehicle
     * @param manufacturer manufacturer of Vehicle
     * @param mileage mileage of Vehicle in kilometres
     * @param horsepower horsepower of Vehicle
     * @param maxSpeed max speed of Vehicle in km/h
     * @param color color of Vehicle
     * @param type type of vehicle (any derived class)
     */
    Vehicle(std::string name, double price, int wheels, int doors, int seats, int maxPassengers,
            std::string manufacturer, double mileage, double horsepower, double maxSpeed, std::string color, std::string type);

    /**
     * Start the car if possible
     * @return if the car was started
     */
    bool start();

    /**
     * Stop the car if possible
     * @return if the car was stopped
     */
    bool stop();

    /**
     * Make the vehicle drive a certain distance
     * @param distance the distance driven, in km
     * @return Whether the drive was successful (distance was non-negative)
     */
    bool drive(double distance);

    /**
     * Add a driver to the vehicle
     * @param driver pointer to driver
     * @return Whether a driver was successfully added
     */
    bool addDriver(Person *driver);

    /**
     * Remove the driver from the vehicle
     * @return Whether the driver was successfully removed
     */
    bool removeDriver();

    /**
     * Change the color of the vehicle
     * @param newColor the new color
     * @return Whether the color was successfully changed
     */
    bool changeColor(const std::string &newColor);

    /**
     * Change the price of the vehicle
     * @param newPrice the new price
     * @return Whether the price was successfully changed
     */
    bool changePrice(double newPrice);

    /**
     * Get the max speed of the vehicle in km/h
     * @return max speed of vehicle in km/h
     */
    double getMaxSpeed() const;

    /**
     * Get the number of wheels that the vehicle has
     * @return # of wheels that vehicle has
     */
    int getWheels() const;

    /**
     * Get the number of doors that the vehicle has
     * @return # of doors that vehicle has
     */
    int getDoors() const;

    /**
     * Get the number of seats that the vehicle has
     * @return # of seats that vehicle has
     */
    int getSeats() const;

    /**
     * Get the horsepower available from the vehicle's engine
     * @return the amount of horsepower of the vehicle
     */
    double getHorsepower() const;

    /**
     * Get the price of the vehicle in dollars
     * @return price of the vehicle in dollars
     */
    double getPrice() const;

    /**
     * Get the name of the vehicle
     * @return name of the vehicle
     */
    std::string getName() const;

    /**
     * Get the UUID of the vehicle
     * @return
     */
    std::string getUUID() const;

    /**
     * Roughly approximate the fuel usage for the vehicle to travel a certain amount of kilometres.
     * @param kilometres Number of kilometres
     * @return Fuel usage in litres
     */
    virtual double approximateFuelUsageFromKm(double kilometres) = 0;

    /**
     * Serialize all the data in the class into JSON.
     * @return serialized JSON data of the class
     */
    virtual json serializeToJSON();

    /**
     * Sanitize the JSON data that should be deserialized into a derived class of Vehicle.
     * @param data the JSON data to sanitize
     * @return the sanitized JSON data
     * @throws runtime_error if required key does not exist
     */
    static json getSanitizedJSON(const json &data);

    /**
     * Save the data in the instance as a JSON file in its expected location.
     * The filename of the saved file is the UUID.
     */
    virtual void saveAsFile();

    /**
     * Prepares the information within the Vehicle class to be printed as a string.
     * @return formatted string of all of the info in Vehicle
     */
    virtual std::string toFormattedString();

    /**
     * Convert the data in the instance into a string
     * @param out the current output stream to add onto
     * @param obj reference to Vehicle to get data from
     * @return the manipulated output stream with the Vehicle data
     */
    friend std::ostream &operator<<(std::ostream &out, Vehicle &obj);

protected:
    std::string name;
    double price;
    int wheels;
    int doors;
    int seats;
    int maxPassengers;
    double maxSpeed;
    std::string manufacturer;
    double mileage;
    double horsepower;
    Person *driver;
    bool started;
    std::string color;
    std::string uuid;
    std::string type;
};