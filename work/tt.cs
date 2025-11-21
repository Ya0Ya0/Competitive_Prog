using Microsoft.SqlServer.TransactSql.ScriptDom;
using System;
using System.Collections.Generic;
//#include <winternl.h>
class  SQLVisitor : TSqlFragmentVisitor
    {
        public int position = 0;
        // Store parent statement hash codes for each statement
        public Dictionary<TSqlFragment, int> ParentHashMap = new Dictionary<TSqlFragment, int>();


        public override void ExplicitVisit(SelectStatement stmt)
        {
            // Store parent's hash code if available
            RecordParentHashCode(stmt);

            if (stmt.Into != null)
                AnalyseSelectIntoStatement(stmt);
            else
                AnalyseSelectStatement(stmt);
        }

        public override void ExplicitVisit(InsertStatement stmt)
        {
            // Store parent's hash code if available
            RecordParentHashCode(stmt);

            AnalyseInsertStatement(stmt);
        }

        // ... your AnalyseSelectIntoStatement, AnalyseSelectStatement, and AnalyseInsertStatement methods ...

        private void RecordParentHashCode(TSqlFragment stmt)
        {
            if (stmt.Parent != null)
            {
              
                ParentHashMap[stmt] = stmt.Parent.GetHashCode(); 
            }
            else
            {
                // Handle the case where there's no parent (e.g., the root statement)
                // You might assign a special value like -1 or not add it to the dictionary.
                 ParentHashMap[stmt] = -1; // Example: using -1 for no parent
            }
        }





    }