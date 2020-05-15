// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var Raw = { };

var query = "query ($arg: SampleField!)  {\nenumInput(arg: $arg)  \n}\n";

function parse(value) {
  return {
          enumInput: value.enumInput
        };
}

function serialize(value) {
  var value$1 = value.enumInput;
  return {
          enumInput: value$1
        };
}

function serializeVariables(inp) {
  var a = inp.arg;
  return {
          arg: a !== 225952583 ? (
              a >= 382368628 ? "SECOND" : "FIRST"
            ) : "THIRD"
        };
}

function makeVariables(arg, param) {
  return serializeVariables({
              arg: arg
            });
}

var definition = /* tuple */[
  parse,
  query,
  serialize
];

var Z__INTERNAL = {
  _graphql_arg_82: 0,
  _graphql_arg_77: 0,
  _graphql_SampleField_47: 0,
  graphql_module: 0
};

var MyQuery = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  definition: definition,
  Z__INTERNAL: Z__INTERNAL
};

exports.MyQuery = MyQuery;
/* No side effect */