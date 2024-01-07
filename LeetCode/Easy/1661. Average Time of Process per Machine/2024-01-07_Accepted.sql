SELECT
    Activity.machine_id,
    ROUND(AVG(Copy.timestamp - Activity.timestamp), 3) AS processing_time
  FROM Activity
  INNER JOIN Activity AS Copy
    ON Activity.machine_id = Copy.machine_id AND Activity.process_id = Copy.process_id
        AND Activity.activity_type = 'start' AND Copy.activity_type = 'end'
  GROUP BY Activity.machine_id;
