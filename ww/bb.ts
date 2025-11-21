// import { escapeLiteral } from "./aa";
// import _ from "lodash";
// import { expect } from 'chai';

// describe("escapeLiteral", () => {
//   it("should escape null", () => {
//     expect(escapeLiteral(null)).toBe("null");
//   });

//   it("should escape strings", () => {
//     expect(escapeLiteral("hello")).toBe("'hello'");
//     expect(escapeLiteral("it's")).toBe("'it''s'");
//     expect(escapeLiteral("hello\\world")).toBe("E'hello\\\\world'");
//     expect(escapeLiteral("'\"\\")).toBe("E'''\\"\\\\'"); // Test combination of quotes and backslash
//   });

//   it("should escape numbers", () => {
//     expect(escapeLiteral(123)).toBe("123");
//     expect(escapeLiteral(-456)).toBe("-456");
//     expect(escapeLiteral(123.456)).toBe("123.456");
//     expect(escapeLiteral(1.1234567890)).toBe("1.123456789"); // Javascript Number doesn't inherently retain specified precision past a point
//     expect(escapeLiteral(Number(1.1234567890.toFixed(10)))).toBe("1.123456789");  // More precise decimal places
//   });


//   it("should escape booleans", () => {
//     expect(escapeLiteral(true)).toBe("TRUE");
//     expect(escapeLiteral(false)).toBe("FALSE");
//   });

//   it("should escape arrays", () => {
//     expect(escapeLiteral([1, 2, 3])).toBe("array[1,2,3]");
//     expect(escapeLiteral(["a", "b", "c"])).toBe("array['a','b','c']");
//     expect(escapeLiteral([true, false, null])).toBe("array[TRUE,FALSE,null]");
//     // Nested array
//     expect(escapeLiteral([1, [2, [3, 4]]])).toBe("array[1,array[2,array[3,4]]]");
//   });

//   it("should escape dates", () => {
//     const date = new Date("2023-10-27T10:00:00.000Z");
//     expect(escapeLiteral(date)).toBe("'2023-10-27T10:00:00.000Z'");
//   });


//   it("should escape objects as json", () => {
//     const obj = { a: 1, b: "hello" , c: 1.1234567890  };
//     expect(escapeLiteral(obj)).toBe("('{\"a\":1,\"b\":\"hello\",\"c\":1.123456789}'::json)");
//   });

//   it("should throw error for unsupported types", () => {
//     expect(() => escapeLiteral(Symbol("test"))).toThrowError("Unsupported literal value: Symbol(test)");
//     expect(() => escapeLiteral(() => {})).toThrowError(); // Function will also throw an error

//     const unsupportedObject = { toJSON: () => {throw new Error("Cannot serialize")}};
//     expect(() => escapeLiteral(unsupportedObject)).toThrowError();

//   });



//   it("should escape large numbers correctly", () => {
//     const largeNumber = 123456789012345678901234567890n;  // BigInt
//     expect(() => escapeLiteral(largeNumber)).toThrowError("Unsupported literal value"); // Currently throws an error
//   });

// });