[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module MyQuery' = {
  module Raw = {
    type t_customScalarField = {
      nullable: Js.Nullable.t(Js.Json.t),
      nonNullable: Js.Json.t,
    };
    type t = {customScalarField: t_customScalarField};
    type t_variables = {
      opt: Js.Nullable.t(Js.Json.t),
      req: Js.Json.t,
    };
  };
  let query = "query ($opt: CustomScalar, $req: CustomScalar!)  {\ncustomScalarField(argOptional: $opt, argRequired: $req)  {\nnullable  \nnonNullable  \n}\n\n}\n";
  type t_customScalarField = {
    nullable: option(Js.Json.t),
    nonNullable: Js.Json.t,
  };
  type t = {customScalarField: t_customScalarField};
  type t_variables = {
    opt: option(Js.Json.t),
    req: Js.Json.t,
  };
  let parse: Raw.t => t =
    (value) => (
      {
        customScalarField: {
          let value = (value: Raw.t).customScalarField;
          (
            {
              nullable: {
                let value = (value: Raw.t_customScalarField).nullable;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              },
              nonNullable: {
                let value = (value: Raw.t_customScalarField).nonNullable;
                value;
              },
            }: t_customScalarField
          );
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let customScalarField = {
          let value = (value: t).customScalarField;
          (
            {
              let nonNullable = {
                let value = (value: t_customScalarField).nonNullable;
                value;
              }
              and nullable = {
                let value = (value: t_customScalarField).nullable;
                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              };
              {nullable, nonNullable};
            }: Raw.t_customScalarField
          );
        };
        {customScalarField: customScalarField};
      }: Raw.t
    );
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      opt:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables).opt,
        ),
      req: (a => a)((inp: t_variables).req),
    };
  let makeVariables = (~opt=?, ~req, ()) =>
    serializeVariables({opt, req}: t_variables);
  module Z__INTERNAL = {
    type nonrec _graphql_opt_119;
    /**Variable **$opt** has the following graphql type:

```
CustomScalar
```*/
    let _graphql_opt_119: _graphql_opt_119 = Obj.magic(0);
    type nonrec _graphql_argOptional_106;
    /**Argument **argOptional** on field **customScalarField** has the following graphql type:

```
CustomScalar
```*/
    let _graphql_argOptional_106: _graphql_argOptional_106 = Obj.magic(0);
    type nonrec _graphql_req_138;
    /**Variable **$req** has the following graphql type:

```
CustomScalar!
```*/
    let _graphql_req_138: _graphql_req_138 = Obj.magic(0);
    type nonrec _graphql_argRequired_125;
    /**Argument **argRequired** on field **customScalarField** has the following graphql type:

```
CustomScalar!
```*/
    let _graphql_argRequired_125: _graphql_argRequired_125 = Obj.magic(0);
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery = {
  include MyQuery';
  let self:
    module GraphQL_PPX.Query with
      type t_variables = MyQuery'.t_variables and
      type Raw.t_variables = MyQuery'.Raw.t_variables and
      type t = MyQuery'.t and
      type Raw.t = MyQuery'.Raw.t =
    (module MyQuery');
};
