"use strict";

var Cylon = require("cylon");

Cylon.robot({
  connections: {
    leap: { adaptor: "leapmotion" },
    arduino: { adaptor: "firmata", port: "/dev/cu.usbserial-A1019F8X" }
  },

  devices: {
    led: { driver: "led", pin: 2, connection: "arduino" }
  },

  work: function(my) {
    my.leap.on("frame", function(frame) {
      if (frame.hands.length > 0) {
        my.led.turnOn();
      } else {
        my.led.turnOff();
      }
    });
  }
}).start();