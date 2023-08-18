-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Checking the description of the crime happened at the given location and time.
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28;
-- Look at transcript of interviews
SELECT transcript FROM interviews WHERE month = 7 AND day = 28;
--Select people who went to withdraw money on the 28th of JULY at Leggett Street
SELECT name FROM people, bank_accounts, atm_transactions
WHERE people.id = bank_accounts.person_id
AND bank_accounts.account_number = atm_transactions.account_number
AND month = 7 AND day = 28 AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";
-- Select people who had drove their car away at specific time
SELECT name FROM people, bakery_security_logs
WHERE people.license_plate = bakery_security_logs.license_plate
AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;
-- Select Name of people who called another person for less than 60 seconds
SELECT * FROM people, bakery_security_logs, phone_calls
WHERE people.license_plate = bakery_security_logs.license_plate
AND people.phone_number = phone_calls.caller
AND phone_calls.month = 7 AND phone_calls.day = 28 AND hour = 10 AND minute > 15 AND minute < 25
AND duration < 60;
-- Find the list of passengers who left on 29th earliest plane
SELECT * from people, passengers, flights
WHERE people.passport_number = passengers.passport_number
AND passengers.flight_id = flights.id
AND month = 7 AND day = 29;
-- Phone records
SELECT * FROM people, phone_calls
WHERE people.phone_number = phone_calls.caller
AND name = "Bruce"
AND month = 7 AND day = 28;
-- Select Location (New York City)
SELECT * FROM airports WHERE id = 4;
-- Select name of accomplice
SELECT name FROM people WHERE phone_number = "(375) 555-8161";
SELECT * FROM people, passengers, flights
WHERE people.passport_number = passengers.passport_number
AND passengers.flight_id = flights.id
AND month = 7 AND day = 29 AND hour = 8 AND minute = 20;