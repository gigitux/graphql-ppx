// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var Raw = { };

var query = "query   {\nvariousScalars  {\nstring  \nint  \n}\n\n}\n";

function parse(value) {
  var value$1 = value.variousScalars;
  return {
          variousScalars: {
            string: value$1.string,
            int: value$1.int
          }
        };
}

function serialize(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.int;
  var value$3 = value$1.string;
  var variousScalars = {
    string: value$3,
    int: value$2
  };
  return {
          variousScalars: variousScalars
        };
}

var definition = /* tuple */[
  parse,
  query,
  serialize
];

var Z__INTERNAL = {
  graphql_module: 0
};

var MyQuery = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  definition: definition,
  Z__INTERNAL: Z__INTERNAL
};

var Raw$1 = { };

var query$1 = "query   {\nvariousScalars  {\nnullableString  \n}\n\n}\n";

function parse$1(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.nullableString;
  return {
          variousScalars: {
            nullableString: (value$2 == null) ? undefined : value$2
          }
        };
}

function serialize$1(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.nullableString;
  var nullableString = value$2 !== undefined ? value$2 : null;
  var variousScalars = {
    nullableString: nullableString
  };
  return {
          variousScalars: variousScalars
        };
}

var definition$1 = /* tuple */[
  parse$1,
  query$1,
  serialize$1
];

var Z__INTERNAL$1 = {
  graphql_module: 0
};

var OneFieldQuery = {
  Raw: Raw$1,
  query: query$1,
  parse: parse$1,
  serialize: serialize$1,
  definition: definition$1,
  Z__INTERNAL: Z__INTERNAL$1
};

var query$2 = "fragment Fragment on VariousScalars   {\nstring  \nint  \n}\n";

var Raw$2 = { };

function parse$2(value) {
  return {
          string: value.string,
          int: value.int
        };
}

function serialize$2(value) {
  var value$1 = value.int;
  var value$2 = value.string;
  return {
          string: value$2,
          int: value$1
        };
}

var name = "Fragment";

var Z__INTERNAL$2 = {
  graphql: 0,
  graphql_module: 0
};

var Fragment = {
  query: query$2,
  Raw: Raw$2,
  parse: parse$2,
  serialize: serialize$2,
  name: name,
  Z__INTERNAL: Z__INTERNAL$2
};

var Raw$3 = { };

var query$3 = "query   {\nvariousScalars  {\n...Fragment   \n}\n\n}\nfragment Fragment on VariousScalars   {\nstring  \nint  \n}\n";

function parse$3(value) {
  return {
          variousScalars: parse$2(value.variousScalars)
        };
}

function serialize$3(value) {
  var value$1 = value.variousScalars;
  var variousScalars = serialize$2(value$1);
  return {
          variousScalars: variousScalars
        };
}

var definition$2 = /* tuple */[
  parse$3,
  query$3,
  serialize$3
];

var Z__INTERNAL$3 = {
  graphql_module: 0
};

var Untitled1 = {
  Raw: Raw$3,
  query: query$3,
  parse: parse$3,
  serialize: serialize$3,
  definition: definition$2,
  Z__INTERNAL: Z__INTERNAL$3
};

var ExternalFragmentQuery = {
  Fragment: Fragment,
  Untitled1: Untitled1
};

var Raw$4 = { };

var query$4 = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n}\n\n}\n";

function parse$4(value) {
  var value$1 = value.dogOrHuman;
  var typename = value$1["__typename"];
  var tmp = typename === "Dog" ? /* `Dog */[
      3406428,
      {
        name: value$1.name,
        barkVolume: value$1.barkVolume
      }
    ] : /* `FutureAddedValue */[
      -31101740,
      value$1
    ];
  return {
          dogOrHuman: tmp
        };
}

function serialize$4(value) {
  var value$1 = value.dogOrHuman;
  var dogOrHuman;
  if (value$1[0] >= 3406428) {
    var value$2 = value$1[1];
    var value$3 = value$2.barkVolume;
    var value$4 = value$2.name;
    dogOrHuman = {
      __typename: "Dog",
      name: value$4,
      barkVolume: value$3
    };
  } else {
    dogOrHuman = value$1[1];
  }
  return {
          dogOrHuman: dogOrHuman
        };
}

var definition$3 = /* tuple */[
  parse$4,
  query$4,
  serialize$4
];

var Z__INTERNAL$4 = {
  graphql_module: 0
};

var InlineFragmentQuery = {
  Raw: Raw$4,
  query: query$4,
  parse: parse$4,
  serialize: serialize$4,
  definition: definition$3,
  Z__INTERNAL: Z__INTERNAL$4
};

var query$5 = "fragment DogFragment on Dog   {\nname  \nbarkVolume  \n}\n";

var Raw$5 = { };

function parse$5(value) {
  return {
          name: value.name,
          barkVolume: value.barkVolume
        };
}

function serialize$5(value) {
  var value$1 = value.barkVolume;
  var value$2 = value.name;
  return {
          name: value$2,
          barkVolume: value$1
        };
}

var name$1 = "DogFragment";

var Z__INTERNAL$5 = {
  graphql: 0,
  graphql_module: 0
};

var DogFragment = {
  query: query$5,
  Raw: Raw$5,
  parse: parse$5,
  serialize: serialize$5,
  name: name$1,
  Z__INTERNAL: Z__INTERNAL$5
};

var Raw$6 = { };

var query$6 = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n...DogFragment   \n}\n\n}\n\n}\nfragment DogFragment on Dog   {\nname  \nbarkVolume  \n}\n";

function parse$6(value) {
  var value$1 = value.dogOrHuman;
  var typename = value$1["__typename"];
  var tmp = typename === "Dog" ? /* `Dog */[
      3406428,
      parse$5(value$1)
    ] : /* `FutureAddedValue */[
      -31101740,
      value$1
    ];
  return {
          dogOrHuman: tmp
        };
}

function serialize$6(value) {
  var value$1 = value.dogOrHuman;
  var dogOrHuman = value$1[0] >= 3406428 ? serialize$5(value$1[1]) : value$1[1];
  return {
          dogOrHuman: dogOrHuman
        };
}

var definition$4 = /* tuple */[
  parse$6,
  query$6,
  serialize$6
];

var Z__INTERNAL$6 = {
  graphql_module: 0
};

var Untitled1$1 = {
  Raw: Raw$6,
  query: query$6,
  parse: parse$6,
  serialize: serialize$6,
  definition: definition$4,
  Z__INTERNAL: Z__INTERNAL$6
};

var UnionExternalFragmentQuery = {
  DogFragment: DogFragment,
  Untitled1: Untitled1$1
};

exports.MyQuery = MyQuery;
exports.OneFieldQuery = OneFieldQuery;
exports.ExternalFragmentQuery = ExternalFragmentQuery;
exports.InlineFragmentQuery = InlineFragmentQuery;
exports.UnionExternalFragmentQuery = UnionExternalFragmentQuery;
/* No side effect */