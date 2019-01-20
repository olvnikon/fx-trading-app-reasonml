// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var BuyRate$ReactTemplate = require("./Rate/BuyRate.bs.js");
var SellRate$ReactTemplate = require("./Rate/SellRate.bs.js");
var Triangle$ReactTemplate = require("./Triangle/Triangle.bs.js");

var component = ReasonReact.reducerComponent("CurrencyPair");

function getMainCurrency(pair) {
  return Caml_array.caml_array_get(pair.split(" "), 0);
}

function make(pair, buy, sell, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var isPositiveTrend = self[/* state */1][/* prevBuy */0] < buy;
              var currency = getMainCurrency(pair);
              return React.createElement("section", undefined, React.createElement("header", undefined, React.createElement("h3", undefined, pair)), React.createElement("main", undefined, ReasonReact.element(undefined, undefined, SellRate$ReactTemplate.make(currency, sell, /* array */[])), ReasonReact.element(undefined, undefined, Triangle$ReactTemplate.make(isPositiveTrend, /* array */[])), ReasonReact.element(undefined, undefined, BuyRate$ReactTemplate.make(currency, buy, /* array */[]))));
            }),
          /* initialState */(function (param) {
              return /* record */[/* prevBuy */0.0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _state) {
              return /* Update */Block.__(0, [/* record */[/* prevBuy */action[0]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.getMainCurrency = getMainCurrency;
exports.make = make;
/* component Not a pure module */
