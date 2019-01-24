// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Caml_format = require("bs-platform/lib/js/caml_format.js");
var HomeConstants$ReactTemplate = require("./HomeConstants.bs.js");

function multiplyByRandomValue(max, min, value) {
  return Caml_format.caml_float_of_string((value * (Math.random() * (min - max) + max)).toFixed(5));
}

function shouldPairUpdate(param) {
  return Math.random() < HomeConstants$ReactTemplate.pairChangeProbability;
}

function multiplyByRandom(param) {
  return multiplyByRandomValue(HomeConstants$ReactTemplate.minMultiplier, HomeConstants$ReactTemplate.maxMultiplier, param);
}

function getPairWithUpdatedRate(param) {
  return /* Pair */[
          param[0],
          multiplyByRandom(param[1]),
          multiplyByRandom(param[2])
        ];
}

function mapPairs(param) {
  var sell = param[2];
  var buy = param[1];
  var pair = param[0];
  var match = Math.random() < HomeConstants$ReactTemplate.pairChangeProbability;
  if (match) {
    return getPairWithUpdatedRate(/* Pair */[
                pair,
                buy,
                sell
              ]);
  } else {
    return /* Pair */[
            pair,
            buy,
            sell
          ];
  }
}

exports.multiplyByRandomValue = multiplyByRandomValue;
exports.shouldPairUpdate = shouldPairUpdate;
exports.multiplyByRandom = multiplyByRandom;
exports.getPairWithUpdatedRate = getPairWithUpdatedRate;
exports.mapPairs = mapPairs;
/* No side effect */
