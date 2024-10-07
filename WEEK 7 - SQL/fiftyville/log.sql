-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
-- 1. bakery    2. 10:15   3. 3 witnesses
SELECT description
  FROM crime_scene_reports
 WHERE year = 2023 AND month = 7 AND day = 28
   AND street = 'Humphrey Street'
   AND description LIKE '%bakery%';

-- Find the transcripts of interviews
-- 1. exit 10:15-10:25
-- 2. withdraw at ATM on Leggett Street
-- 3. the earliest flight for the next day
SELECT name, transcript
  FROM interviews
 WHERE year = 2023 AND month = 7 AND day = 28
   AND transcript LIKE '%bakery%';

-- Find the thief's flight id   (id 36, destination id 4)
SELECT id, destination_airport_id FROM flights
 WHERE year = 2023 AND month = 7 AND day = 29
 ORDER BY hour, minute
 LIMIT 1;

-- Find the destination
-- New York City ★★★
SELECT city FROM airports
 WHERE id = 4;

-- Find the thief. (bakery + phone calls + flight + atm)
-- Bruce ★★★
-- (367) 555-5533
SELECT name, phone_number FROM people
  JOIN bakery_security_logs AS bakery ON people.license_plate = bakery.license_plate
  JOIN phone_calls AS calls ON people.phone_number = calls.caller
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN bank_accounts AS bank ON people.id = bank.person_id
  JOIN atm_transactions AS atm ON bank.account_number = atm.account_number
 WHERE bakery.year = 2023 AND bakery.month = 7 AND bakery.day = 28 AND bakery.hour = 10
   AND bakery.minute >= 15 AND bakery.minute <= 25
   AND bakery.activity = 'exit'
   AND calls.year = 2023 AND calls.month = 7 AND calls.day = 28
   AND calls.duration <= 60
   AND passengers.flight_id = 36
   AND atm.atm_location = 'Leggett Street'
   AND atm.year = 2023 AND atm.month = 7 AND atm.day = 28
   AND atm.transaction_type = 'withdraw';

-- Find the accomplice
-- Robin ★★★
SELECT name FROM people AS p
 WHERE p.phone_number IN
       (SELECT receiver FROM phone_calls AS c
         WHERE c.caller = '(367) 555-5533'
           AND c.year = 2023 AND c.month = 7 AND c.day = 28
           AND c.duration <= 60);
