/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.sink;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct(value="FinalResponse", builder=FinalResponse.Builder.class)
public final class FinalResponse {
    @ThriftConstructor
    public FinalResponse(
        @ThriftField(value=1, name="content", requiredness=Requiredness.NONE) final String content
    ) {
        this.content = content;
    }
    
    @ThriftConstructor
    protected FinalResponse() {
      this.content = null;
    }
    
    public static class Builder {
        private String content;
        @ThriftField(value=1, name="content", requiredness=Requiredness.NONE)
        public Builder setContent(String content) {
            this.content = content;
            return this;
        }
    
        public Builder() { }
        public Builder(FinalResponse other) {
            this.content = other.content;
        }
    
        @ThriftConstructor
        public FinalResponse build() {
            return new FinalResponse (
                this.content
            );
        }
    }
    
    private final String content;

    
    @ThriftField(value=1, name="content", requiredness=Requiredness.NONE)
    public String getContent() { return content; }
    
    @Override
    public String toString() {
        return toStringHelper(this)
            .add("content", content)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        FinalResponse other = (FinalResponse)o;
    
        return
            Objects.equals(content, other.content) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            content
        });
    }
    
}
